/*
 * =====================================================================================
 *
 *! \brief Filename:  SpinalMesh.h
 *
 *    Description: The class defines functions for a generic k-ary 2D SpinalMesh
 *    with the network being a direct network of size n=k^2.
 *
 *    In order to understand connections the port assigned is as follows
 *
 *    Router ports
 *    ************ SEND DATA *********
 *    port 0: Connects to interface
 *    port 1: Connects to WEST going
 *    port 2: Connects to EAST going
 *    port 3: Connects to NORTH going
 *    port 4: Connects to SOUTH going
 *    ************ SEND SIGNAL *********
 *    port p: Connects to interface
 *    port p+1: Connects to WEST going
 *    port p+2: Connects to EAST going
 *    port p+3: Connects to NORTH going
 *    port p+4: Connects to SOUTH going
 *    ************ INCOMING DATA *********
 *    port 2p: Connects to interface
 *    port 2p+1: Connects to WEST going
 *    port 2p+2: Connects to EAST going
 *    port 2p+3: Connects to NORTH going
 *    port 2p+4: Connects to SOUTH going
 *    ************ INCOMING SIGBAL *********
 *    port 3p: Connects to interface
 *    port 3p+1: Connects to WEST going
 *    port 3p+2: Connects to EAST going
 *    port 3p+3: Connects to NORTH going
 *    port 3p+4: Connects to SOUTH going
 *
 *              a links
 *              ----> R0 ----> R1 ---->
 *              <---  |^ <---  |^   <---
 *              blinks
 *                    ||       ||
 *                    v|       v|
 *              ----> R2 ----> R3 ---->
 *                  a  |^  b
 *                     ||
 *                  l  ||  l
 *                  i  V|  i
 *                  n      n
 *                  k      k
 *                  s      s
 *
 *        Version:  1.0
 *        Created:  05/05/2010 12:01:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mitchelle Rasquinha
 *        Company:  Georgia Institute of Technology
 *
 * =====================================================================================
 */

#ifndef _SpinalMesh_h_INC
#define _SpinalMesh_h_INC

#include "topology.h"

extern std::vector<ManifoldProcessor *> g_macsim_terminals;

class SpinalMesh : public Topology {
 private:
  SpinalMesh();  // DO NOT USE (use the public one)
 public:
  SpinalMesh(macsim_c *simBase);
  ~SpinalMesh();

  void parse_config(std::map<std::string, std::string> &p);

  void connect_interface_terminal(void);
  void connect_interface_routers(void);
  void connect_routers(void);
  void assign_node_ids(component_type t);

  std::string print_stats(void);
  std::string print_stats(component_type t);
  void set_router_outports(uint n);

 protected:
  vector<uint> &split(const string &s, char delim, vector<uint> &elems);
  vector<uint> split(const std::string &s, char delim);

 private:
  uint ports;
  uint vcs;
  uint credits;
  uint buffer_size;
  uint links;
  uint no_nodes;
  uint dim;
  uint grid_size;
  vector<uint> mapping;

  macsim_c *m_simBase; /**< macsim_c base class for simulation globals */

}; /* -----  end of class SpinalMesh  ----- */

#endif /* ----- #ifndef _SpinalMesh_h_INC  ----- */
