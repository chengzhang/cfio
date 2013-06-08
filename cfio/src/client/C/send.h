/****************************************************************************
 *       Filename:  send.h
 *
 *    Description:  define for msg between IO process and IO forwarding process
 *
 *        Version:  1.0
 *        Created:  12/13/2011 10:39:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wang Wencan 
 *	    Email:  never.wencan@gmail.com
 *        Company:  HPC Tsinghua
 ***************************************************************************/
#ifndef _SEND_H
#define _SEND_H
#include <stdlib.h>

#define SEND_BUF_SIZE ((size_t)1024*1024*1024)
#define SEND_MSG_MIN_SIZE ((size_t)70*1024*1024)

/**
 * @brief: init the buffer and msg queue
 *
 * @return: error code
 */
int cfio_send_init();

/**
 * @brief: finalize , free the buffer and msg queue
 *
 * @return: error code
 */
int cfio_send_final();

/**
 * @brief: pack cfio_create function into struct cfio_msg_t
 *
 * @param path: the file name of the new netCDF dataset, cfio_create's
 *	arg
 * @param cmode: the creation mode flag , arg of cfio_create
 * @param ncid: ncid assigned by client
 *
 * @return: error code
 */
int cfio_send_create(
	const char *path, int cmode, int ncid);

/**
 * @brief: pack cfio_def_dim into msg
 *
 * @param ncid: NetCDF group ID, arg of cfio_def_dim
 * @param name: Dimension name, arg of cfio_def_dim
 * @param len: Length of dimension, arg of cfio_def_dim
 * @param dimid: dim id assigned by client
 *
 * @return: error_code
 */
int cfio_send_def_dim(
	int ncid, const char *name, size_t len, int dimid);

/**
 * @brief: pack cfio_def_var into msg
 *
 * @param ncid: netCDF ID, arg of cfio_def_var
 * @param name: variable name, arg of cfio_def_var
 * @param xtype: predefined netCDF external data type, arg of 
 *	cfio_def_var
 * @param ndims: number of dimensions for the variable, arg of 
 *	cfio_def_var
 * @param dimids: vector of ndims dimension IDs corresponding to the
 *	variable dimensions, arg of cfio_def_var
 * @param start: a vector of size_t intergers specifying the index in 
 *	the variable where the first of the data values will be written,
 *	arg of cfio_put_vara_float
 * @param count: a vector of size_t intergers specifying the edge lengths
 *	along each dimension of the block of data values to be written, 
 *	arg of cfio_put_vara_float
 * @param varid: var id assigned by client
 *
 * @return: error code
 */
int cfio_send_def_var(
	int ncid, const char *name, nc_type xtype,
	int ndims, const int *dimids, 
	const size_t *start, const size_t *count, int varid);

/**
 * @brief: pack cfio_put_att into msg
 *
 * @param ncid: netCDF ID, arg of cfio_put_att
 * @param varid: variable ID, arg of cfio_put_att
 * @param name: variable name, arg of cfio_put_att
 * @param xtype: predefined netCDF external data type, arg of cfio_put_att
 * @param len: number of values provided for the attribute
 * @param op: Pointer to values
 *
 * @return: error code
 */
int cfio_send_put_att(
	int ncid, int varid, const char *name, 
	nc_type xtype, size_t len, const void *op);

/**
 * @brief: pack cfio_enddef into msg
 
 * @param ncid: netCDF ID, arg of cfio_enddef
 *
 * @return: error code
 */
int cfio_send_enddef(
	int ncid);

/**
 * @brief: pack cfio_put_vara_float into msg
 *
 * @param ncid: netCDF ID, arg of cfio_put_vara_float
 * @param varid: variable ID, arg of cfio_put_vara_float
 * @param ndims: the dimensionality fo variable
 * @param start: a vector of size_t intergers specifying the index in 
 *	the variable where the first of the data values will be written,
 *	arg of cfio_put_vara_float
 * @param count: a vector of size_t intergers specifying the edge lengths
 *	along each dimension of the block of data values to be written, 
 *	arg of cfio_put_vara_float
 * @param fp_type: type of data, can be CFIO_BYTE, CFIO_CHAR, CFIO_SHROT, 
 *	CFIO_INT, CFIO_FLOAT, CFIO_DOUBLE
 * @param fp : pointer to where data is stored, arg of 
 *	cfio_put_vara_float
 *
 * @return: 
 */
int cfio_send_put_vara(
	int ncid, int varid, int ndims,
	const size_t *start, const size_t *count, 
	const int fp_type, const void *fp);

/**
 * @brief: pack cfio_close into msg
 *
 * @param ncid: netCDF ID, arg of cfio_close
 *
 * @return: error code
 */
int cfio_send_close(
	int ncid);

/**
 * @brief: pack a special msg, the msg will inform the server that one
 *	client's IO is over
 *
 * @return: error code
 */
int cfio_send_io_done();

int cfio_send_pause();
int cfio_send_resume();

#endif
