//
//  Table.h
//  Breakout
//
//  Created by Edward on 9/28/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef Table_h
#define Table_h
#include "Block.h"

class Table {
private:
    const float PADDING = 45;
    //will need a way to get block's width
    const float BLOCK_WIDTH = 100;
    const float BLOCK_HEIGHT = 32;
    Block*** table;
    int row, column;
    
public:
    Table(int row, int column, std::string file_path, sf::RenderWindow &window) {
        this->row = row;
        this->column = column;
        table = new Block**[row];
        for(int i = 0; i < row; ++i)
            table[i] = new Block*[column];
        populateTable(file_path, window);
    };
    
    ~Table() {
        for(int i = 0; i < row ; ++i)
            delete [] table[i];
        delete [] table;
    }
    
    //For now populate all the rows and columns in table
    void populateTable(std::string file_path, sf::RenderWindow &window) {
        
        sf::Vector2f init_pos = {PADDING , (float) (window.getSize().y * (0.1f))};
        
        for (int i = 0; i < row ; i++) {
            for (int k = 0; k < column; k++) {
                table[i][k] = new Block(file_path, init_pos);
                //now add the width of block to X
                init_pos.x += BLOCK_WIDTH;
            }
            //reset X position
            //now add the height of block to Y
            init_pos.x = PADDING;
            init_pos.y += BLOCK_HEIGHT;
        }
    }
    
    void drawObjects(sf::RenderWindow &window) {
        for (int i = 0; i < row ; i++) {
            for (int k = 0; k < column; k++) {
                table[i][k]->draw(window);
            }
        }
    }
    
    
};



#endif /* Table_h */
