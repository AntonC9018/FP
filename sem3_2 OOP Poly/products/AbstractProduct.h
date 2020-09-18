#pragma once

class AbstractProduct
{
public:
    virtual void PromptInputAll() = 0;
    virtual void PrintAll() const = 0;
};