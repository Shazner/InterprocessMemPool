//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/CppCon2018
//
// Modified by Keith Rausch

#ifndef BOOST_BEAST_EXAMPLE_WEBSOCKET_CHAT_MULTI_LISTENER_HPP
#define BOOST_BEAST_EXAMPLE_WEBSOCKET_CHAT_MULTI_LISTENER_HPP

#include "beast.h"
#include "net.h"
#include <boost/smart_ptr.hpp>
#include <memory>
#include <string>


namespace IPC
{

// Forward declaration
class shared_state;

// Accepts incoming connections and launches the sessions
class listener : public std::enable_shared_from_this<listener>
{
  net::io_context &ioc_;
  tcp::acceptor acceptor_;
  std::shared_ptr<shared_state> state_;

  void fail(beast::error_code ec, char const *what);
  void on_accept(beast::error_code ec, tcp::socket socket);

public:
  tcp::endpoint localEndpoint;

  listener(
      net::io_context &ioc,
      tcp::endpoint endpoint,
      std::shared_ptr<shared_state> const &state);

  // Start accepting incoming connections
  void run();
};

} // namespace

#endif