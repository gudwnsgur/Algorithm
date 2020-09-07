using namespace std;
#define ll long long

ll gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return (long long)a;
}

long long solution(int w, int h) {
	ll answer = (ll)w*h;
	answer -= gcd(w, h)*((ll)w / gcd(w, h) + (ll)h / gcd(w, h) - 1);
	return answer;
}