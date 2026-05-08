#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Goal: Connect to a local server on port 8080, send "Hello", and print response.
    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        close(sockfd);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    
    // Bug 1: Port byte order (htons is missing!)
    server_addr.sin_port = htons(8080); 

    // Bug 2: IP address conversion (inet_addr or inet_pton is missing!)
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        close(sockfd);
        return 1;
    }

    // Step 2: Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        // Bug 3: If connect fails, the socket should be closed!
        close(sockfd);
        return 1;
    }

    char *msg = "Hello from client!";
    send(sockfd, msg, strlen(msg), 0);

    // Step 3: Receive response
    // Bug 4: Not handling the null terminator for the string in 'buffer'!
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Server said: %s\n", buffer);
    }

    // Bug 5: Forgetting to close the socket!

    close(sockfd);
    return 0;
}
