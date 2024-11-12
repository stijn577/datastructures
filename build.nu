
def build [] {
  if not ("build" | path exists) {
    cmake -S . -G "Unix Makefiles" -B build
  }
  cd build
  make
}

def run [] {
  build
  ./build/bin/app.exe
}

def test [] {
  build
  cd build
  make test
}

def ftest [] {
  build
  cd build
  ctest --rerun-failed --output-on-failure
}

def clean [] {
  rm -rf build
  rm -rf .cache
}
