import os
import sys
import subprocess
import platform
import multiprocessing
from pathlib import Path

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):
    def build_extension(self, ext: CMakeExtension) -> None:
        # Directory where the extension will be placed.
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        if not extdir.endswith(os.path.sep):
            extdir += os.path.sep

        # Determine build configuration.
        debug = int(os.environ.get("DEBUG", 0)) if self.debug is None else self.debug
        cfg = "Debug" if debug else "Release"

        # CMake configuration arguments.
        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}",
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-DCMAKE_BUILD_TYPE={cfg}",
        ]

        # Build arguments.
        build_args = ["--config", cfg]

        # Platform-specific configuration.
        if platform.system() == "Windows":
            cmake_args += [f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{cfg.upper()}={extdir}"]
            if "CMAKE_GENERATOR" not in os.environ:
                cmake_args += ["-A", "x64" if sys.maxsize > 2**32 else "Win32"]
        else:
            if not os.environ.get("CMAKE_BUILD_TYPE"):
                cmake_args += [f"-DCMAKE_BUILD_TYPE={cfg}"]

        # Add extra CMake args from environment.
        if "CMAKE_ARGS" in os.environ:
            cmake_args += [item for item in os.environ["CMAKE_ARGS"].split() if item]

        # Set parallel build level.
        if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
            if hasattr(self, "parallel") and self.parallel:
                build_args += [f"-j{self.parallel}"]
            else:
                build_args += [f"-j{multiprocessing.cpu_count()}"]

        # Create build directory.
        build_temp = Path(self.build_temp)
        build_temp.mkdir(parents=True, exist_ok=True)

        # Run CMake configuration.
        subprocess.check_call(
            ["cmake", ext.sourcedir, *cmake_args],
            cwd=build_temp,
        )

        # Run CMake build.
        subprocess.check_call(
            ["cmake", "--build", ".", *build_args],
            cwd=build_temp,
        )

setup(
    ext_modules=[CMakeExtension("eigen_ops")],
    cmdclass={"build_ext": CMakeBuild},
)
