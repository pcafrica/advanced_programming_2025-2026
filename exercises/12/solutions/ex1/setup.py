from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

__version__ = "1.0.0"

ext_modules = [
    Pybind11Extension(
        "data_processor",
        ["data_processor.cpp"],
        cxx_std=17,
        extra_compile_args=["-O3", "-Wall", "-Wextra"],
    ),
]

setup(
    name="data_processor",
    version=__version__,
    author="Pasquale Claudio Africa",
    author_email="pafrica@sissa.it",
    description="A data processor module using C++ and pybind11",
    long_description="A simple example of Python bindings for a C++ data processing class using pybind11",
    long_description_content_type="text/plain",
    ext_modules=ext_modules,
    install_requires=["pybind11>=2.10.0"],
    python_requires=">=3.7",
    cmdclass={"build_ext": build_ext},
    zip_safe=False
)
