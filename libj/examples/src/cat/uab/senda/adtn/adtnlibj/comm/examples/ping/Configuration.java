package cat.uab.senda.adtn.adtnlibj.comm.examples.ping;

import cat.uab.senda.adtn.adtnlibj.comm.SockAddrT;

public class Configuration {
    //Default values

    public String dest_platform_id;
    public long payload_size;
    public int ping_count;
    public int ping_interval;
    public long ping_lifetime;
    SockAddrT source, destination;
 
    Configuration(String dest_platform_id, String size, String count, String interval, String lifetime ){
        this.dest_platform_id = dest_platform_id;
        this.payload_size = Integer.parseInt(size);
        this.ping_count = Integer.parseInt(count);
        this.ping_interval = Integer.parseInt(interval);
        this.ping_lifetime = Integer.parseInt(lifetime);
    }

    public String getDest_platform_id() {
        return dest_platform_id;
    }

    public void setDest_platform_id(String dest_platform_id) {
        this.dest_platform_id = dest_platform_id;
    }

    public long getPayload_size() {
        return payload_size;
    }

    public void setPayload_size(long payload_size) {
        this.payload_size = payload_size;
    }

    public int getPing_count() {
        return ping_count;
    }

    public void setPing_count(int ping_count) {
        this.ping_count = ping_count;
    }

    public int getPing_interval() {
        return ping_interval;
    }

    public void setPing_interval(int ping_interval) {
        this.ping_interval = ping_interval;
    }

    public long getPing_lifetime() {
        return ping_lifetime;
    }

    public void setPing_lifetime(long ping_lifetime) {
        this.ping_lifetime = ping_lifetime;
    }
    
     public SockAddrT getSource() {
        return source;
    }

    public void setSource(SockAddrT source) {
        this.source = source;
    }

    public SockAddrT getDestination() {
        return destination;
    }

    public void setDestination(SockAddrT destination) {
        this.destination = destination;
    }
}
