# Create the build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build

# Run CMake to generate the build files
cmake ..

# Build the project
make