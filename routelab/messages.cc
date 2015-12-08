#include "messages.h"

RoutingMessage::RoutingMessage()
{}

RoutingMessage::RoutingMessage(const RoutingMessage &rhs) {
    *this = rhs;
}

RoutingMessage & RoutingMessage::operator=(const RoutingMessage & rhs) {
    /* For now.  Change if you add data members to the struct */
    return *this;
}

#if defined(GENERIC)
ostream &RoutingMessage::Print(ostream &os) const
{
    os << "Generic RoutingMessage()";
    return os;
}
#endif

#if defined(LINKSTATE)
RoutingMessage::RoutingMessage(int a, int src, int dest, int lat) {
  link_age = a;
  src_node = src;
  dest_node = dest;
  new_latency = lat;
}

ostream &RoutingMessage::Print(ostream &os) const
{
    os << "\nLinkState RoutingMessage():";
    os << "Source: " << src_node << std::endl;
    os << "Destination: " << dest_node << std::endl;
    os << "Weight: " << new_latency << std::endl; 
    return os;
}
#endif

#if defined(DISTANCEVECTOR)
// Message includes the sending node number and that nodes distance vector
RoutingMessage::RoutingMessage(int s, map<int, TopoLink> DV) {
  sendingNode = s;
  distanceVector = DV;
}

ostream &RoutingMessage::Print(ostream &os) const
{
    os << "DistanceVector RoutingMessage()";
    return os;
}
#endif
