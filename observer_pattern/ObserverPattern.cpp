#include "subject.h"
#include "displayObserver.h"
#include "audioObserver.h"

int main()
{
    Subject* subject = new Subject();
    DisplayObserver* display = new DisplayObserver(subject);
    AudioObserver* audio = new AudioObserver(subject);
    subject->setKey('k');
    subject->dettach(audio);
    subject->setMousePos(12,12);
}