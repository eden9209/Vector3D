#include <iostream>
using namespace std;
#include <cmath>
const double epsilon = 0.001;


template<typename T>
class Vector3d{
private:
	T x;
	T y;
	T z;

public:
	Vector3d(T xcor,T ycor,T zcor);
 	 Vector3d();
	void add(Vector3d vec);
	void sub(Vector3d vec);
	T dot(Vector3d vec);
	double abs();
	T getx();
	T gety();
	T getz();
	void setx(T xcor);
	void sety(T ycor);
	void setz(T zcor);


	   Vector3d curl(Vector3d vec)
	   {
		   Vector3d temp;
		   	temp.x=(y*vec.z)-(vec.y*z);
		   	temp.y=(z*vec.x)-(x*vec.z);
		     temp.z=(x*vec.y)-(y*vec.x);
		     return temp;
	   }

	   friend std::ostream& operator<<(std::ostream& out, const Vector3d& val){
	  	        out <<"("<< val.x<<","<<val.y<<","<<val.z<<")";
	  	        return out;
	  	    }


	   Vector3d operator +(Vector3d v)
	   {
		    Vector3d temp;
		   	temp.x=x+v.x;
		   	temp.y=y+v.y;
		   	temp.z=z+v.z;
		   return temp;
	   }

	   bool operator == (Vector3d vec)
		{
           double res=sqrt(x*x+y*y+z*z);

           return res-vec.abs()==0;

		}
	   bool operator < (Vector3d vec)
	   		{
		    double res=sqrt(x*x+y*y+z*z);
		  	return (vec.abs()-res>epsilon);

	   		}

	   bool operator > (Vector3d vec)
	   	   		{
		             double res=sqrt(x*x+y*y+z*z);
		   	         return (res-vec.abs()>epsilon);

	   	   		}

	   bool operator != (Vector3d vec)
	   		{
	              double res=sqrt(x*x+y*y+z*z);

	              return res-vec.abs()!=0;

	   		}


};



template<typename T>
void Vector3d<T>::sub(Vector3d vec)
{
	this -> x=x-vec.getx();
	this -> y=y-vec.gety();
	this -> z=z-vec.getz();

}

template<typename T>
T Vector3d<T>::dot(Vector3d vec)
{
	return(x*vec.getx()+y*vec.gety()+z*vec.getz());
}

template<typename T>
double Vector3d<T>::abs()
{
	return(sqrt(x*x+y*y+z*z));
}

template<typename T>
Vector3d<T>::Vector3d(T elemOne, T elemTwo, T elemThree)
{
    x = elemOne;
    y = elemTwo;
    z = elemThree;
}

//implement default constructor
template<typename T>
Vector3d<T>::Vector3d()
{
}

template<typename T>
void Vector3d<T>::add(Vector3d vec)
{
	this ->x=x+vec.getx();
	this ->y=y+vec.gety();
	this ->z=z+vec.getz();
}

/////////////getters and setters
template<typename T>
T Vector3d<T>::getx()
{
	return this -> x;
}

template<typename T>
T Vector3d<T>::gety()
{
	return this -> y;
}

template<typename T>
T Vector3d<T>::getz()
{
	return this -> z;
}

template<typename T>
void Vector3d<T>::setx(T xcor)
{
	this -> x=xcor;
}

template<typename T>
void Vector3d<T>::sety(T ycor)
{
	this -> y=ycor;
}

template<typename T>
void Vector3d<T>::setz(T zcor)
{
	this -> z=zcor;
}
////////////////////

int main()
{
	Vector3d<int> a(1,1,2);
	Vector3d<int> b(2,1,1);
	double dot=a.dot(b);
	Vector3d<int> c;
    c=a.curl(b);

    cout<<"the dot product of a and b is:";
	cout<<dot<<endl;
	cout<<"the curl of vector a and b is:";
	cout<<c<<endl;
	cout<<"the abs of a is: "<<a.abs()<<endl;
	cout<<"addition of a+b :"<<a+b<<endl;

	return 0;
}
