function color_transfer_files(srcfile, tgtfile)

src = im2double(imread (srcfile));
tgt = im2double(imread (tgtfile));

src_lAB = rgb2lAB(src);
tgt_lAB = rgb2lAB(tgt);

dst_lAB = color_transfer(src_lAB, tgt_lAB);

dst = lAB2rgb(dst_lAB);

[srcdir, srcname, srcext, srcver] = fileparts(srcfile);
[tgtdir, tgtname, tgtext, tgtver] = fileparts(tgtfile);

imwrite(dst, fullfile(srcdir, ["src", srcname, "tgt", tgtname, ".png"]))
%imwrite(fullfile(srcdir, ["src", srcname, "tgt", tgtname, ".png"]), dst(:,:,1), dst(:,:,2), dst(:,:,3));
