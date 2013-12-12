% -*- octave -*-

function lms = rgb2lms(rgb)

mat = [.3811 .5783 .0402;
       .1967 .7244 .0782;
       .0241 .1288 .8444];

lms = im_lin_color_trans(rgb, mat);
