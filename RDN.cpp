Int rdn(int dd,int mm,int yy){
int tm=mm, ty=yy;
if (mm<3) ty–, tm+=12;
return 365*ty+ty/4-ty/100+ty/400+(153*tm-457)/5+dd-306-1;
}
