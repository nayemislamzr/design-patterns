#include <iostream>
#include <string>
#include <vector>

class Camera
{
public :
    Camera() = default;
    void StartRecording()
    {
        _state = true;
        std::cout << "Recording Started...\n";
    }
    void stopRecording()
    {
        _state = false;
        std::cout << "Recording Stopped...\n";
    }
    void rotateCamera(float angle)
    {
        std::cout << "Camera rotated " << angle << " degree.\n";
    }
    bool state() const
    {
        return _state;
    }
private :
    bool _state = false;
};

class Light
{
public :
    Light() = default;
    void turnOnLight()
    {
        std::cout << "Turning on Light...\n";
    }
    void turnOffLight()
    {
        std::cout << "Turning off Light...\n";
    }
};

class Speaker
{
public :
    Speaker() = default;
    void turnOnSpeaker()
    {
        std::cout << "Turning on Speaker...\n";
    }
    void turnOffSpeaker()
    {
        std::cout << "Turning off Speaker...\n";
    }
    void increaseVolume()
    {
        std::cout << "Increasing volume...\n";
    }
    void decreaseVolume()
    {
        std::cout << "Decreasing volume...\n";
    }
};

class Command
{
public :
    Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class StartRecording : public Command
{
public :
    StartRecording() = delete;
    StartRecording(Camera* camera)
        : theCamera{camera}
    {

    }
    virtual void execute() override
    {
        if(theCamera->state() == false)
        {
            theCamera->StartRecording();
        }
    }
    virtual void undo() override
    {
        if(theCamera->state() == true)
        {
            theCamera->stopRecording();
        }
    }
private :
    Camera* theCamera;
};

class CommandManager
{
public :
    CommandManager() = default;
    void add(Command* command)
    {
        commands.emplace_back(command);
    }
    void executeAll()
    {
        for(Command* command : commands)
        {
            command->execute();
        }
        commands.clear();
    }
private :
    std::vector<Command*> commands;
};

int main()
{
    CommandManager* manager = new CommandManager();
    Command* startRecordingCommand = new StartRecording(new Camera());
    manager->add(startRecordingCommand);
    manager->executeAll();
}