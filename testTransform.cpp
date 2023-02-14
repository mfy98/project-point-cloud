 #include "Transform.h"
using namespace std;
 
 
 int main() {
     Point p, p2;
 
     p.setx(0);
     p.sety(0);
     p.setz(5);
 
     Transform t;
     double ang[3] = { 0, 0, -90 };
     double tr[3] = { 100, 500, 50 };
	 for ( int i = 0;  i <3;  i++)
	 {
		 t.setAngles(ang);
		 t.setTrans(tr);
	 }
  

     
 
     p2 = t.doTransform(p);
 
     for (int i = 0; i < 3; i++)
         cout << t.getTrans() << endl;
     return 0;
 }