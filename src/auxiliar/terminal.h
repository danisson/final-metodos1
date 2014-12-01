#ifndef TERMINAL
#define TERMINAL
inline void goUp(int dy) {
	printf("\e[%dA",dy);
}
inline void goDown(int dy) {
	printf("\e[%dB",dy);
}
inline void goRight(int dx) {
	printf("\e[%dC",dx);
}
inline void goLeft(int dx) {
	printf("\e[%dD",dx);
}
inline void clean() {
	printf("\e[0;0H\e[2J");
}
#endif