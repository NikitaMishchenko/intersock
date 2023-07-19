#include <iostream>

#include <string>

#include <boost/asio.hpp>

std::string read_(boost::asio::ip::tcp::socket &socket)
{
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    std::string data = boost::asio::buffer_cast<const char *>(buf.data());
    return data;
}
void send_(boost::asio::ip::tcp::socket &socket, const std::string &message)
{
    const std::string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}

int main(int argc, char **argv)
{
    boost::asio::io_service io_service;
    
    // listen for new connection
    boost::asio::ip::tcp::acceptor acceptor_(io_service, 
                                             boost::asio::ip::tcp::endpoint( boost::asio::ip::tcp::v4(), 1234));
    
    // socket creation
    boost::asio::ip::tcp::socket socket_(io_service);
    
    // waiting for connection
    acceptor_.accept(socket_);
    
    // read operation
    std::string message = read_(socket_);
    
    std::cout << message << std::endl;
    
    // write operation
    send_(socket_, "Hello From Server!");
    
    std::cout << "Servent sent Hello message to Client!" << std::endl;
    
    return 0;
}
