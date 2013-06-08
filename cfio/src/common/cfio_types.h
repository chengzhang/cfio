/****************************************************************************
 *       Filename:  cfio_types.h
 *
 *    Description:  define data types in cfio
 *
 *        Version:  1.0
 *        Created:  08/20/2012 03:30:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wang Wencan 
 *	    Email:  never.wencan@gmail.com
 *        Company:  HPC Tsinghua
 ***************************************************************************/
#include "netcdf.h"

#define CFIO_BYTE   NC_BYTE
#define CFIO_CHAR   NC_CHAR
#define CFIO_SHORT  NC_SHORT
#define CFIO_INT    NC_INT
#define CFIO_FLOAT  NC_FLOAT
#define CFIO_DOUBLE NC_DOUBLE

#define cfio_types_size(size, type) \
    do{				    \
    switch(type) {		    \
	case CFIO_BYTE :	    \
	    size = 1;		    \
	    break;		    \
	case CFIO_CHAR :	    \
	    size = 1;		    \
	    break;		    \
	case CFIO_SHORT :	    \
	    size = sizeof(short);   \
	    break;		    \
	case CFIO_INT :		    \
	    size = sizeof(int);	    \
	    break;		    \
	case CFIO_FLOAT :	    \
	    size = sizeof(float);   \
	    break;		    \
	case CFIO_DOUBLE :	    \
	    size = sizeof(double);  \
	    break;		    \
    }} while(0)
