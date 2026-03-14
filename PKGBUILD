pkgname=smoothysearch
pkgver=0.2.1
pkgrel=1
pkgdesc="Minimal launcher for Linux built with Rust and Qt/QML"
arch=('x86_64')
url="https://github.com/Wemite/smoothysearch"
license=('custom')
depends=(
  'qt6-base'
  'qt6-declarative'
)
makedepends=(
  'cargo'
  'clang'
  'cmake'
  'lld'
)
options=('!lto')
provides=('smoothysearch')
conflicts=('smoothysearch')
source=(
  'smoothysearch.desktop'
  'smoothysearch-themer.desktop'
  'smoothysearch-service.desktop'
  'smoothysearch.png'
)

sha256sums=('SKIP' 'SKIP' 'SKIP')

sha256sums=('SKIP' 'SKIP' 'SKIP' 'SKIP')

build() {
  cd "$startdir"
  export CARGO_PROFILE_RELEASE_LTO=false
  cargo build --release --locked
}

package() {
  cd "$startdir"

  install -Dm755 "target/release/smoothysearch" \
    "$pkgdir/usr/bin/smoothysearch"

  install -Dm644 "smoothysearch.desktop" \
    "$pkgdir/usr/share/applications/smoothysearch.desktop"

  install -Dm644 "smoothysearch-themer.desktop" \
    "$pkgdir/usr/share/applications/smoothysearch-themer.desktop"

  install -Dm644 "smoothysearch.png" \
    "$pkgdir/usr/share/icons/hicolor/256x256/apps/smoothysearch.png"

  install -Dm644 "smoothysearch-service.desktop" \
    "$pkgdir/etc/xdg/autostart/smoothysearch-service.desktop"

  install -Dm644 "LICENSE" \
    "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
