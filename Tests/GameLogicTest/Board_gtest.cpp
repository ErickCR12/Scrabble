#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../gameLogic/Board.hpp"
#include "../../gameLogic/LetterTile.hpp"

using testing::Eq;

namespace {
    Board* b = new Board();

    // Inicializacion del tablero
    TEST(BoardTest,Initialization){

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

    // Insertar una letra en el Tablero
    TEST(BoardTest,Insertion){
        // Añadir una ficha al tablero
        LetterTile *tile = new LetterTile("a",1,1);
        b->addLetterTile(2,3,tile);

        // Comparar que la ficha se añade
        ASSERT_STREQ("a",(b->getLetterTile(2,3))->getLetter().c_str());

    }


}

