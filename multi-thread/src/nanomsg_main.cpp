#include <iostream>
#include <string.h>
#include <thread>
#include <assert.h>
#include <unistd.h>
#include <sys/prctl.h>

#include "nn.h"
#include "pubsub.h"


#include "nanomsg_publisher.h"
#include "nanomsg_subscriber.h"



using namespace std;

int main() {


    auto pub_thread = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread1 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub1.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread1 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub1.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });







    auto pub_thread2 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub2.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread2 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub2.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });







    auto pub_thread3 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub3.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread3 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub3.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread4 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub4.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread4 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub4.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread5 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub5.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread5 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub5.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread6 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub6.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread6 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub6.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread7 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub7.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread7 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub7.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread8 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub8.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread8 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub8.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread9 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub9.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread9 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub9.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread10 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub10.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread10 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub10.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread11 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub11.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread11 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub11.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread12 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub12.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread12 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub12.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread13 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub13.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread13 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub13.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread14 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub14.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread14 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub14.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread15 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub15.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread15 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub15.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread16 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub16.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread16 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub16.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread17 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub17.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread17 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub17.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread18 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub18.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread18 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub18.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread19 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub19.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread19 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub19.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread20 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub20.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread20 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub20.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread21 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub21.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread21 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub21.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread22 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub22.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread22 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub22.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread23 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub23.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread23 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub23.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });






    auto pub_thread24 = std::thread([&]() {
        int pub_sock;
        string url = "ipc:///tmp/nanomsg_pub24.sock";

        if (0 != send_sock_init(&pub_sock, url.c_str())) {
            return 1;
        }

        while (true) {
            send_data(pub_sock);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto sub_thread24 = std::thread([&]() {
        string  url = "ipc:///tmp/nanomsg_pub24.sock";
        int sub_sock;
        if (0 != recieve_sock_init(&sub_sock, url.c_str())) {
            return;
        }

        while (true) {
            char *buf;
            int recv_len = 0;
            recv_len = nn_recv(sub_sock, &buf, NN_MSG, 0);
            //std::cout << "Message1: " << buf << std::endl;
            nn_freemsg(buf);
            if (recv_len < 0) {
                std::cout << "recv message failed" << std::endl;
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });























    pub_thread.join();
    sub_thread.join();


    pub_thread1.join();
    sub_thread1.join();


    pub_thread2.join();
    sub_thread2.join();


    pub_thread3.join();
    sub_thread3.join();


    pub_thread4.join();
    sub_thread4.join();


    pub_thread5.join();
    sub_thread5.join();


    pub_thread6.join();
    sub_thread6.join();


    pub_thread7.join();
    sub_thread7.join();


    pub_thread8.join();
    sub_thread8.join();


    pub_thread9.join();
    sub_thread9.join();


    pub_thread10.join();
    sub_thread10.join();


    pub_thread11.join();
    sub_thread11.join();


    pub_thread12.join();
    sub_thread12.join();


    pub_thread13.join();
    sub_thread13.join();


    pub_thread14.join();
    sub_thread14.join();


    pub_thread15.join();
    sub_thread15.join();


    pub_thread16.join();
    sub_thread16.join();


    pub_thread17.join();
    sub_thread17.join();


    pub_thread18.join();
    sub_thread18.join();


    pub_thread19.join();
    sub_thread19.join();


    pub_thread20.join();
    sub_thread20.join();


    pub_thread21.join();
    sub_thread21.join();


    pub_thread22.join();
    sub_thread22.join();


    pub_thread23.join();
    sub_thread23.join();


    pub_thread24.join();
    sub_thread24.join();




    return 0;
}
