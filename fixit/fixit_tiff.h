#ifndef _FIXIT_TIFF
#define _FIXIT_TIFF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <tiffio.h>
#include <tiff.h>

/* define specific exit-codes */
#define FIXIT_TIFF_IS_VALID 0
#define FIXIT_TIFF_IS_CHECKED 1
#define FIXIT_TIFF_IS_CORRECTED 1
#define FIXIT_TIFF_MISSED_OUTFILE -1
#define FIXIT_TIFF_MISSED_INFILE -2
#define FIXIT_TIFF_CMDLINE_ARGUMENTS_ERROR -3
#define FIXIT_TIFF_MEMORY_ALLOCATION_ERROR -4
#define FIXIT_TIFF_DATETIME_RULE_NOT_FOUND -6
#define FIXIT_TIFF_STRING_COPY_ERROR -5
#define FIXIT_TIFF_READ_PERMISSION_ERROR -20
#define FIXIT_TIFF_WRITE_PERMISSION_ERROR -21
#define FIXIT_TIFF_WRITE_ERROR -22

/** 20 comes from TIFF definition 
 */
#define TIFFDATETIMELENGTH 20

int check_datetime (const char *);
int check_baseline (const char *); 
int check_required (const char *); 
int cleanup_datetime (const char *);
int cleanup_baseline (const char *); 
int cleanup_tagorder (const char *);
int TIFFGetRawTagListCount (TIFF * tif);
uint32 TIFFGetRawTagListEntry( TIFF  * tif, int tagidx );
void print_baseline_tags (TIFF * tif);
void print_required_tags (TIFF * tif);
int test_plausibility (int * year, int * month, int * day, int * hour, int * min, int * sec);

#define FLAGGED 1
#define UNFLAGGED 0

static int flag_be_verbose;

#define count_of_baselinetags 36
const static uint32 baselinetags[count_of_baselinetags]={
  TIFFTAG_SUBFILETYPE,
  TIFFTAG_OSUBFILETYPE,
  TIFFTAG_IMAGEWIDTH,
  TIFFTAG_IMAGELENGTH,
  TIFFTAG_BITSPERSAMPLE,
  TIFFTAG_COMPRESSION,
  TIFFTAG_PHOTOMETRIC,
  TIFFTAG_THRESHHOLDING,
  TIFFTAG_CELLWIDTH,
  TIFFTAG_CELLLENGTH,
  TIFFTAG_FILLORDER,
  TIFFTAG_IMAGEDESCRIPTION,
  TIFFTAG_MAKE,
  TIFFTAG_MODEL,
  TIFFTAG_STRIPOFFSETS,
  TIFFTAG_ORIENTATION,
  TIFFTAG_SAMPLESPERPIXEL,
  TIFFTAG_ROWSPERSTRIP,
  TIFFTAG_STRIPBYTECOUNTS,
  TIFFTAG_MINSAMPLEVALUE,
  TIFFTAG_MAXSAMPLEVALUE,
  TIFFTAG_XRESOLUTION,
  TIFFTAG_YRESOLUTION,
  TIFFTAG_PLANARCONFIG,
  TIFFTAG_FREEOFFSETS,
  TIFFTAG_FREEBYTECOUNTS,
  TIFFTAG_GRAYRESPONSEUNIT,
  TIFFTAG_GRAYRESPONSECURVE,
  TIFFTAG_RESOLUTIONUNIT,
  TIFFTAG_SOFTWARE,
  TIFFTAG_DATETIME,
  TIFFTAG_ARTIST,
  TIFFTAG_HOSTCOMPUTER,
  TIFFTAG_COLORMAP,
  TIFFTAG_EXTRASAMPLES,
  TIFFTAG_COPYRIGHT
};

#define count_of_required_baselinetags 12
const static uint32 required_baselinetags[count_of_required_baselinetags]={
  TIFFTAG_IMAGEWIDTH,
  TIFFTAG_IMAGELENGTH,
  TIFFTAG_COMPRESSION,
  TIFFTAG_PHOTOMETRIC,
  TIFFTAG_STRIPOFFSETS,
  TIFFTAG_SAMPLESPERPIXEL,
  TIFFTAG_ROWSPERSTRIP,
  TIFFTAG_STRIPBYTECOUNTS,
  TIFFTAG_XRESOLUTION,
  TIFFTAG_YRESOLUTION,
  TIFFTAG_RESOLUTIONUNIT,
  TIFFTAG_BITSPERSAMPLE
};



#endif 
/* _FIXIT_TIFF */
