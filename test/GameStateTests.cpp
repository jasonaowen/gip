//
//  GameStateTests.cpp
//  GIP
//
//  Created by gwendolyn weston on 3/6/17.
//
//

#include "catch.hpp"
#include "../src/GameState.hpp"

TEST_CASE("moving left moves left") {
    GameState state = GameState(10, 10);
    Point initialPaddle = state.paddle;

    state.handleAction(Action::LEFT);

    CHECK(initialPaddle.x - 1 == state.paddle.x);
}


TEST_CASE("moving past wall does not move left") {
    GameState state = GameState(10, 10);
    state.paddle.x = 0;

    state.handleAction(Action::LEFT);

    CHECK(state.paddle.x == 0);
}

TEST_CASE("moving right moves right") {
    GameState state = GameState(10, 10);
    Point initialPaddle = state.paddle;

    state.handleAction(Action::RIGHT);

    CHECK(initialPaddle.x + 1 == state.paddle.x);
}


TEST_CASE("moving past wall does not move right") {
    GameState state = GameState(10, 10);
    state.paddle.x = state.worldWidth;

    state.handleAction(Action::RIGHT);

    CHECK(state.paddle.x == state.worldWidth);
}

TEST_CASE("fire right bullet fires a bullet from the right!!") {
    GameState state = GameState(10, 10);

    CHECK(state.bullets.size() == 0);

    state.handleAction(Action::FIRE_RIGHT_BULLET);

    REQUIRE(state.bullets.size() == 1);
    CHECK(state.bullets[0] == state.rightTentacle);
}

TEST_CASE("fire left bullet fires a bullet from the left!!") {
    GameState state = GameState(10, 10);

    CHECK(state.bullets.size() == 0);

    state.handleAction(Action::FIRE_LEFT_BULLET);

    REQUIRE(state.bullets.size() == 1);
    CHECK(state.bullets[0] == state.leftTentacle);
}
