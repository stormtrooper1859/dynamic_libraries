int m_gcd(int a, int b) {
    return b ? m_gcd(b, a % b) : a;
}
