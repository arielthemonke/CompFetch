pkgname=compfetch
pkgver=1.0
pkgrel=1
pkgdesc="I'm just learning cpp and thought it would be fun to make something like this to learn"
arch=('x86_64')
license=('MIT')
makedepends=('gcc')
depends=('playerctl')
source=('main.cpp')
md5sums=('SKIP')

build() {
    g++ -o "$pkgname" "$srcdir/main.cpp"
}

package() {
    install -Dm755 "$pkgname" "$pkgdir/usr/bin/$pkgname"
}