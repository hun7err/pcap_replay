#include <stdio.h>
#include <pcap.h>

#define BATCH_SIZE  1024

// TODO: formatting/different convention (more C-like)
// TODO: multi-threading

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char ** argv) {
    char *device = "", error_buffer[PCAP_ERRBUF_SIZE];

    if(argc < 2) {
        printf("Usage: %s file_name [device]\n", argv[0]);
        return 0;
    }

    if(argc == 3)
        device = argv[2];
   
    // TODO: add device handling
    // TODO: add interrupt handler
    // TODO: MAC printing
    printf("Starting with device: %s\n", device);

    pcap_t *handle = pcap_open_offline(argv[1], error_buffer);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open the pcap file: %s\n", error_buffer);
        return 2;
    }

    u_char *arguments = NULL;

    while(true) {
        pcap_loop(handle, BATCH_SIZE, packet_handler, arguments);
    }

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // send the packet
}
