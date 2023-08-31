default: build

# Set compiler
KOKKOS_PATH = $(shell pwd)/kokkos
CXX = hipcc
# CXX = ${KOKKOS_PATH}/bin/nvcc_wrapper

# Variables for the Makefile.kokkos
KOKKOS_DEVICES = "HIP"
# KOKKOS_DEVICES = "Cuda"
KOKKOS_ARCH = "VEGA90A"
# KOKKOS_ARCH = "Volta70"
KOKKOS_CUDA_OPTIONS = "enable_lambda,force_uvm"

# Include Makefile.kokkos
include $(KOKKOS_PATH)/Makefile.kokkos

build: $(KOKKOS_LINK_DEPENDS) $(KOKKOS_CPP_DEPENDS) hello.cpp
    $(CXX) $(KOKKOS_CPPFLAGS) $(KOKKOS_CXXFLAGS) $(KOKKOS_LDFLAGS) hello.cpp $(KOKKOS_LIBS) -o hello
