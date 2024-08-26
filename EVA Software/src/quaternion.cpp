#include "../include/quaternion.h"

quaternion::quaternion(float a, float b, float c, float d) {
  qa = a;
  qb = b;
  qc = c;
  qd = d;
}

quaternion::quaternion(const quaternion& q1) {
  qa = q1.a();
  qb = q1.b();
  qc = q1.c();
  qd = q1.d();
}

//roll pitch yaw, got functions from https://stackoverflow.com/questions/5782658/extracting-yaw-from-a-quaternion

float quaternion::getRoll() {
  return atan2(2.0 * (qd * qc + qa * qb) , 1.0 - 2.0 * (qb * qb + qc * qc));
}

float quaternion::getPitch() {
  return asin(2.0 * (qc * qa - qd * qb));
}

float quaternion::getYaw() {
  return atan2(2.0 * (qd * qa + qb * qc) , - 1.0 + 2.0 * (qa * qa + qb * qb));
}

float quaternion::norm() const {
  return (float) sqrt(qa * qa + qb * qb + qc * qc + qd * qd);
}

//free functions for operations
quaternion conj(const quaternion& q) {
  return quaternion(q.a(), -q.b(), -q.c(), -q.d());
}
//debating making this a member function
quaternion normalize(const quaternion& q) {
  float n = q.norm();
  return quaternion((q.a() / n), (q.b() / n), (q.c() / n), (q.d() / n));
}

quaternion vector(const quaternion& q) {
  return quaternion(0, q.b(), q.c(), q.d());
}

//operators

quaternion operator*(const quaternion& q1, const quaternion& q2) {
  float new_a = q1.a() * q2.a() - q1.b() * q2.b() - q1.c() * q2.c() - q1.d() * q2.d();
  float new_b = q1.a() * q2.b() + q1.b() * q2.a() + q1.d() * q2.c() - q1.c() * q2.d();
  float new_c = q1.a() * q2.c() + q1.c() * q2.a() + q1.b() * q2.d() - q1.d() * q2.b();
  float new_d = q1.a() * q2.d() + q1.d() * q2.a() + q1.c() * q2.b() - q1.b() * q2.c();
  
  return quaternion(new_a, new_b, new_c, new_d);;
}

quaternion operator*(float M, const quaternion &q) {
  return quaternion((q.a() * M), (q.b() * M), (q.c() * M), (q.d() * M));
}

quaternion operator/(const quaternion &q, float M) {
  return quaternion((q.a() / M), (q.b() / M), (q.c() / M), (q.d() / M));
}

quaternion operator+(const quaternion& q1, const quaternion& q2) {
  return quaternion((q1.a() + q2.a()), (q1.b() + q2.b()), (q1.c() + q2.c()), (q1.d() + q2.d()));
}

quaternion operator-(const quaternion& q1, const quaternion& q2) {
  return quaternion((q1.a() - q2.a()), (q1.b() - q2.b()), (q1.c() - q2.c()), (q1.d() - q2.d()));
}
