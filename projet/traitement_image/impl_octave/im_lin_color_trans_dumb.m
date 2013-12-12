% -*- octave -*-

function img = im_lin_color_trans_dumb(img, mat)

for i = 1:size(img, 1)
  for j = 1:size(img, 2)
    img(i, j, :) = mat * squeeze(img(i, j, :));
  endfor
endfor
