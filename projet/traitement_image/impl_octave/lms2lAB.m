% -*- octave -*-

function lAB = lms2lAB(lms)

epsilon = 1e-10;

mat = diag([1/sqrt(3) 1/sqrt(6) 1/sqrt(2)]) * ...
      [ 1  1  1;
        1  1 -2;
        1 -1 0 ];

lAB = im_lin_color_trans(log(lms + epsilon), mat);
