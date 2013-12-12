function color_transfer_files_rgb(srcfile, tgtfile)

src = im2double(imread (srcfile));
tgt = im2double(imread (tgtfile));

dst = color_transfer(src, tgt);

[srcdir, srcname, srcext, srcver] = fileparts(srcfile);
[tgtdir, tgtname, tgtext, tgtver] = fileparts(tgtfile);

imwrite(fullfile(srcdir, ["RGBsrc", srcname, "tgt", tgtname, ".png"]), dst(:,:,1), dst(:,:,2), dst(:,:,3));
