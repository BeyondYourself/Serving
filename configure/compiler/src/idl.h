/* -*- c++ -*- 
   copy[write] by dirlt(zhang_yan@baidu.com)
   date time:Wed Nov 19 23:33:00 CST 2008
   file name:idl.h */

#ifndef _IDL_H_
#define _IDL_H_

/**
 * @file idl.h
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:33:00 CST 2008
 * @version
 * @brief the interface of internal implementation
 */

#include "idl_conf_if.h"
using namespace confIDL;

/**
 * @brief allocated a meta struct from IDL resource pool
 * @param idl the IDL on which the meta is allocated
 * @return meta allocated
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:33:40 CST 2008
*/
extern meta_t *alloc_meta(idl_t *idl);

/**
 * @brief allocated a constraint function struct from IDL resource pool
 * @param idl the IDL on which the constraint function is allocated
 * @return constraint function allocated
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:33:40 CST 2008
*/
extern cf_t *alloc_cf(idl_t *idl);

/**
 * @brief allocated a variable struct from IDL resource pool
 * @param idl the IDL on which the variable is allocated
 * @return variable allocated
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:33:40 CST 2008
*/
extern var_t *alloc_var(idl_t *idl);

/**
 * @brief allocated a group struct from IDL resource pool
 * @param idl the IDL on which the group is allocated
 * @return group allocated
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:33:40 CST 2008
*/

extern group_t *alloc_group(idl_t *idl);


/**
 * @brief add the error information to the IDL error messages queue
 * @param idl the IDL struct which contains the message queue
 * @param errinfo the error message information
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:36:39 CST 2008
*/
extern void add_idl_error(idl_t *idl,meta_t &errinfo);

/**
 * @brief add the variable struct to the IDL
 * @param idl the IDL struct which contains all variables which described in the IDL file
 * @param var the variable to be added
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:36:39 CST 2008
*/
extern void add_idl_var(idl_t *idl,var_t *var);

/**
 * @brief add the group struct to the IDL
 * @param idl the IDL struct which contains all groups which described in the IDL file
 * @param grp the group to be added
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:36:39 CST 2008
*/
extern void add_idl_group(idl_t *idl,group_t *grp);

/**
 * @brief  assemble the constraint function
 * @param cf the constraint function struct 
 * @param fn the constraint function function name
 * @param arg_list argument list 
 * @see 
 * @note 
 * @author zhang_yan@baidu.com
 * @date Tue Dec  2 11:01:04 CST 2008
*/
extern void assemble_idl_cf(cf_t *cf,meta_t *fn,meta_list_t *arg_list);

/**
 * @brief  assemble the variable 
 * @param idl the idl struct 
 * @param var the variable which to be assembled
 * @param id the variable id
 * @param type the variable type
 * @param cf_list the list of constraint function
 * @note 
 * @author zhang_yan@baidu.com
 * @date Tue Dec  2 11:02:10 CST 2008
*/
extern void assemble_idl_var(idl_t *idl,var_t *var,meta_t *id,meta_t *type,cf_list_t *cf_list);


/**
 * @brief assmeble a group with specific id and fields in it
 * @param idl the IDL struct which contains all groups
 * @param group the group to be assembles
 * @param idl the group name information
 * @param varlist the fields in the group
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:39:26 CST 2008
*/

extern void assemble_idl_group(idl_t *idl,group_t *group,meta_t *id,\
			       var_list_t *varlist);

/**
 * @brief overwrite a old group to generate a new group
 * @param idl the IDL struct which contains all groups
 * @param group the group to be generated by overwriting
 * @param new_id the new group name information
 * @param old_id the old group name information,which will be overwrited 
 * @param varlist the fields to be overwrited 
 * @author zhang_yan@baidu.com
 * @date Wed Nov 19 23:40:59 CST 2008
*/
extern void overwrite_idl_group(idl_t *idl,group_t *group,\
				meta_t *new_id,meta_t *old_id,\
				var_list_t *varlist);


#endif
