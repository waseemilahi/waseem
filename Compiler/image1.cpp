// Data structure for file info functions 
typedef union tagFILEDATA {
	TiffData          tiffdat;
	BITMAPINFOHEADER  bmpdat;
	JpegData          jpegdat;
	PcxData           pcxdat;
	GifData           gifdat;
	TgaData           tgadat;
	} FILEDATA;                     
	
// Determine type of file and load it
int detect_and_load(LPSTR fname, imgdes *image1)
{
   FILEDATA fdata;
   int rcode;
   imgdes timage;
   UINT width, length, bpp;
   int (WINAPI *loadfilefunction)(char *, imgdes *);

   rcode = tiffinfo(fname, &fdata.tiffdat);
   if(rcode == NO_ERROR) {
      loadfilefunction = loadtif;
      width  = fdata.tiffdat.width;
      length = fdata.tiffdat.length;
      bpp    = fdata.tiffdat.vbitcount;
      }
   else {
      rcode = bmpinfo(fname, &fdata.bmpdat);
   	if(rcode == NO_ERROR) {
         loadfilefunction = loadbmp;
         width = (UINT)fdata.bmpdat.biWidth;
         length = (UINT)fdata.bmpdat.biHeight;
         bpp = fdata.bmpdat.biBitCount;
         }
	else {
	   rcode = jpeginfo(fname, &fdata.jpegdat);
	   if(rcode == NO_ERROR) {
            loadfilefunction = loadjpg;
            width = fdata.jpegdat.width;
            length = fdata.jpegdat.length;
            bpp = fdata.jpegdat.vbitcount;
            }
         else {
            rcode = pcxinfo(fname, &fdata.pcxdat);
            if(rcode == NO_ERROR) {
               loadfilefunction = loadpcx;
               width = fdata.pcxdat.width;
               length = fdata.pcxdat.length;
               bpp = fdata.pcxdat.vbitcount;
               }
            else {
               rcode = gifinfo(fname, &fdata.gifdat);
               if(rcode == NO_ERROR) {
                  loadfilefunction = loadgif;
                  width = fdata.gifdat.width;
                  length = fdata.gifdat.length;
                  bpp = fdata.gifdat.vbitcount;
                  }
               }
            }
         }
      }

   if(rcode == NO_ERROR) { // Successfully determined file format
      rcode = allocimage(&timage, width, length, bpp);
      if(rcode == NO_ERROR) {
         rcode = loadfilefunction(fname, &timage);
         if(rcode == NO_ERROR) {
            // Success, free source image
            freeimage(image1);
            // Assign timage to image1
            copyimgdes(&timage, image1);
            }
         }
   }

   return(rcode);
}
