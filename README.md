Fox: Moose Framework custom heat transfert solver
=====
Custom heat transfert kernels and bcs to solve the heat equation:
[^1] A first course in finite elements, T. Belytshko, J. Fish. equation (6.31)

$$\int_{\Omega} (\nabla w)^{T}\cdot k \nabla \theta  d \Omega + \int_{\Gamma_{q}}w \bar q  d\Gamma - \int_{\Omega}w s d \Omega = 0$$

in inner product notation:
$$(\nabla w, k \nabla \theta)  - (w,s)+ (w,\bar q\cdot\vec{n} ) = 0 $$

