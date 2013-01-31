#ifndef DRIVER_DEN_HPP
#define DRIVER_DEN_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

class DentingSection
{
    public:
        DentingSection();
        ~DentingSection();
        void cleanup();

        int getNumVertices();
        void setData(const unsigned short* verts,int numVerts);
        const unsigned short* data();
        unsigned short getVertex(int idx);
        void addVertex(int vidx);
        void removeVertex(int vidx);

    protected:
        int sectionSize;
        unsigned short* sectionData;
};

class DentingEntry
{
    public:
        DentingEntry();
        ~DentingEntry();
        void cleanup();

        DentingSection* getDentingSection(int section);

        int getNumShininessFaces();
        void setShininessData(const unsigned char* data, int numFaces);
        const unsigned char* getShininessData();
        void setFaceShininess(int faceIdx, bool shiny);
        bool faceIsShiny(int faceIdx);

        int getNumTextureIndexFaces();
        void setTextureIndexData(const unsigned char* data, int numFaces);
        const unsigned char* getTextureIndexData();
        int getFaceTextureIndex(int faceIdx);
        void setFaceTextureIntex(int faceIdx, int texIdx);

    protected:
        DentingSection sections[6];
        int numShininessFaces;
        unsigned char* shininessData;
        int numTextureFaces;
        unsigned char* textureNumbers;
};

class DriverDenting
{
    public:
        DriverDenting();
        ~DriverDenting();

        int loadCivilianDentingFromFile(const char* filename);
        int loadCivilianDentingFromFile(FILE* file);
        int loadCivilianDentingFromMemory(const unsigned char* data);

        int loadPlayerDentingFromFile(const char* filename);
        int loadPlayerDentingFromFile(FILE* file);
        int loadPlayerDentingFromMemory(const unsigned char* data);

        int saveCivilianDentingToFile(const char* filename);
        int saveCivilianDentingToFile(FILE* file);
        int saveCivilianDentingToMemory(unsigned char* data);

        int savePlayerDentingToFile(const char* filename);
        int savePlayerDentingToFile(FILE* file);
        int savePlayerDentingToMemory(unsigned char* data);

        DentingEntry* civilianDenting(int idx);
        DentingEntry* playerDenting(int idx);

    protected:
        DentingEntry civilianEntries[11];
        DentingEntry playerEntries[18];
};

#endif
