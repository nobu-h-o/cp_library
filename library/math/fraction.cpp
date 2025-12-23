struct fraction{
  int p,q;
  fraction(int P=0, int Q=1):p(P),q(Q){}
  bool operator<(const fraction &other)const{
    return p*other.q<other.p*q;
  }
  bool operator<=(const fraction &other)const{
    return p*other.q<=other.p*q;
  }
  bool operator>(const fraction &other)const{
    return p*other.q>other.p*q;
  }
  bool operator>=(const fraction &other)const{
    return p*other.q>=other.p*q;
  }
};
