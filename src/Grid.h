////////////////////////////////////////////////////////////////////////////////
// Authors: Vitor Bandeira, Mateus Fogaça, Eder Matheus Monteiro e Isadora
// Oliveira
//          (Advisor: Ricardo Reis)
//
// BSD 3-Clause License
//
// Copyright (c) 2019, Federal University of Rio Grande do Sul (UFRGS)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////

#ifndef __CORE_H_
#define __CORE_H_

#include <vector>

class Grid {
private:
        long _lowerLeftX;
        long _lowerLeftY;
        long _tileWidth;
        long _tileHeight;
        int _xGrids;
        int _yGrids;
        bool _perfectRegularX;
        bool _perfectRegularY;
        int _numLayers;
        std::vector<int> _horizontalEdgesCapacities;
        std::vector<int> _verticalEdgesCapacities;
        
public:
        Grid () = default;
        
        Grid(const long lowerLeftX, const long lowerLeftY,
             const long tileWidth, const long tileHeight,
             const int xGrids, const int yGrids,
             const bool perfectRegularX, const bool perfectRegularY,
             const int numLayers, const std::vector<int> horizontalCapacities,
             const std::vector<int> verticalCapacities)
            : _lowerLeftX(lowerLeftX), _lowerLeftY(lowerLeftY),
              _tileWidth(tileWidth), _tileHeight(tileHeight),
              _xGrids(xGrids), _yGrids(yGrids),
              _perfectRegularX(perfectRegularX),
              _perfectRegularY(perfectRegularY),
              _numLayers(numLayers), _horizontalEdgesCapacities(horizontalCapacities),
              _verticalEdgesCapacities(verticalCapacities) {}
        
        long getLowerLeftX() const { return _lowerLeftX; }
        long getLowerLeftY() const { return _lowerLeftY; }
        
        long getTileWidth() const { return _tileWidth; }
        long getTileHeight() const { return _tileHeight; }
        
        int getXGrids() const { return _xGrids; }
        int getYGrids() const { return _yGrids; }
        
        bool isPerfectRegularX() const { return _perfectRegularX; }
        bool isPerfectRegularY() const { return _perfectRegularY; }
        
        int getNumLayers() const { return _numLayers; }
        
        std::vector<int> getHorizontalEdgesCapacities() { return _horizontalEdgesCapacities; };
        std::vector<int> getVerticalEdgesCapacities() { return _verticalEdgesCapacities; };
        
        void addHorizontalCapacity(int value, int layer) { _horizontalEdgesCapacities[layer] = value; }
        void addVerticalCapacity(int value, int layer) { _verticalEdgesCapacities[layer] = value; }
        
        typedef struct {
                int _x;
                int _y;
        } TILE;
};

#endif /* __CORE_H_ */