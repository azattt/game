#pragma once

#include <string>
#include <fstream>

constexpr int CHUNK_SIZE = 16;
class SaveManager{
  public:
    bool open(std::string path){
        std::fstream file(path, std::ios::app | std::ios::binary);
        return file.is_open();
    }
    void getChunkAt(int x, int y){
        
    }
    ~SaveManager(){
        if (file.is_open()){
            file.close();
        }
    }
  private:
    std::string path;
    std::fstream file;
};