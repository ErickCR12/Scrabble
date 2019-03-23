#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../gameLogic/Board.hpp"

using testing::Eq;

namespace {
    TEST(BoardTest,Initialization){
        Board* b = new Board();

        // Prueba 1. Que la matriz de letterTiles este inicializada a nullptr
        EXPECT_EQ(nullptr,b->getLetterTile(0,0));
        EXPECT_EQ(nullptr,b->getLetterTile(7,7));
        EXPECT_EQ(nullptr,b->getLetterTile(14,14));

        // Prueba 2. Que la matriz de pesos contenga los pesos correctos
        EXPECT_EQ(1,b->getScore(2,3));
        EXPECT_EQ(2,b->getScore(6,2));
        EXPECT_EQ(3,b->getScore(9,9));
        EXPECT_EQ(5,b->getScore(7,7));
    }


}

