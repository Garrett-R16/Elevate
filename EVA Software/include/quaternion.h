#ifndef QUATERNION
#define QUATERNION

//will need to remove iostream
#include <iostream>
#include <cmath>

class quaternion {
  public:

    quaternion(float a, float b, float c, float d);
    quaternion(const quaternion& q1);

    //roll pitch yaw, got functions from https://stackoverflow.com/questions/5782658/extracting-yaw-from-a-quaternion
    //additional note, the order should be zyx order or yaw, pitch, roll
    //based on this visualization https://quaternions.online/, roll is about the x axis, while pitch is towards x and z, and yaw is x and y
    float getRoll();
    float getPitch();
    float getYaw();

    //getters
    float a() const {
      return qa;
    }
    float b() const {
      return qb;
    }
    float c() const {
      return qc;
    }
    float d() const {
      return qd;
    }

    float norm() const;
    //temporary function for testing
    void print() {
      std::cout << qa << ", " << qb << ", " << qc << ", " << qd << std::endl;
    }

  private:
    float qa = 0.0f;
    float qb = 0.0f;
    float qc = 0.0f;
    float qd = 0.0f;
};

//free functions for operations
quaternion conj(const quaternion& q);
//debating making this a member function
quaternion normalize(const quaternion& q);
quaternion vector(const quaternion& q);

//operators

quaternion operator*(const quaternion& q1, const quaternion& q2);
quaternion operator*(float M, const quaternion &q);
quaternion operator/(const quaternion &q, float M);
quaternion operator+(const quaternion& q1, const quaternion& q2);
quaternion operator-(const quaternion& q1, const quaternion& q2);

//more testing
// int main() {
//   quaternion q(1, 1, 1, 1);
//   quaternion q1(2, 2, 2, 2);
//   quaternion q2 = 2*q;
//   quaternion q3 = q2+q1;
//   quaternion q4 = q2-q1;
//   q3.print();
//   q4.print();
//   return 0;
// }

#endif