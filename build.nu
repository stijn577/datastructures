
def build [] {
  if not ("build" | path exists) {
    cmake -S . -G "Unix Makefiles" -B build
  }
  cd build
  make
}

def run [] {
  build
  ./build/app.exe
}

def clean [] {
  rm -rf build
  rm -rf .cache
}
