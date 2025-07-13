#pragma once

class Board;

class BoardRenderer {
public:
    virtual ~BoardRenderer() = default;

    virtual void render(const Board& board) = 0;
};

class ConsoleBoardRenderer : public BoardRenderer {
public:
    void render(const Board& board) override;
};