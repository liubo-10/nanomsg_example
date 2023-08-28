#include <iostream>
#include <string.h>
#include <thread>
#include <assert.h>
#include <unistd.h>
#include <sys/prctl.h>

#include "common.hpp"
#include "nn.h"
#include "pubsub.h"

using namespace std;

int main() {
    int sub_sock, pub_sock;
    int rv, rvt;

    pub_sock = nn_socket(AF_SP, NN_PUB);
    assert(pub_sock >= 0);
    rv = nn_bind(pub_sock, "tcp://127.0.0.1:11910");
    assert(rv >= 0);

    sub_sock = nn_socket(AF_SP, NN_SUB);
    assert(sub_sock >= 0);
    rvt = nn_connect(sub_sock, "tcp://127.0.0.1:11910");
    assert(rvt >= 0);
    rvt = nn_setsockopt(sub_sock, NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
    assert(rvt >= 0);

    string message;
    message = kb_message(1);

    auto pub_thread = std::thread([&]() {
        prctl(PR_SET_NAME, "nanomsg_pub_thread");
        while (true) {
            nn_send(pub_sock, message.c_str(), message.size(), 0);
        }
    });

    auto sub_thread = std::thread([&]() {
        prctl(PR_SET_NAME, "nanomsg_sub_thread");
        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            std::cout << "Message: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
        }
    });

    pub_thread.join();
    sub_thread.join();

    return 0;
}
