#pragma once

#include <list>
#include <typeinfo>
#include <vector>
#include "main.h"
#include "game_object.h"

#define LAYER 3

class CScene {
protected:
    std::list<CGameObject*>	m_GameObject[LAYER];

public:
    CScene() {}
    virtual ~CScene() {}


    virtual void Init() {

    }

    virtual void Uninit() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Uninit();
                delete object;
            }
            m_GameObject[i].clear();
        }
    }


    virtual void Update() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Update();
            }

            m_GameObject[i].remove_if([](auto object) { return object->Destroy(); });
        }
    }


    virtual void Draw() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Draw();
            }
        }
    }


    template <typename T>
    T* AddGameObject(int layer) {
        T* gameObject = new T();
        gameObject->Init();
        m_GameObject[layer].push_back(gameObject);

        return gameObject;
    }

    template <typename T>
    T* GetGameObject() {
        for (int i = 0; i < LAYER; i++) {
            for (auto p : m_GameObject[i]) {
                if (typeid(*p) == typeid(T)) {
                    return (T*)p;
                }
            }
        }
    }
};