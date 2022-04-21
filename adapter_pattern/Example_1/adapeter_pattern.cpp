#include <iostream>
#include <string>

enum class MediaType
{
    AUDIO,
    VIDEO,
    IMAGE
};

enum class MediaQuality
{
    LOW,
    MEDIUM,
    HIGH
};

class MediaPlayer
{
public :
    MediaPlayer() = default;
    virtual void play(MediaType type, MediaQuality quality, const std::string& src) = 0;
};

class AdvancedMediaPlayer
{
public :
    AdvancedMediaPlayer() = default;
    virtual void playVlc(const std::string& src) = 0;
    virtual void playMpv(const std::string& src) = 0;
    virtual void playMp3(const std::string& src) = 0;
};

class AdvancedImagePlayer
{
public :
    AdvancedImagePlayer() = default;
    virtual void imageView(const std::string& src) = 0;
    virtual void snapView(const std::string& src) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer
{
public :
    VlcPlayer() = default;
    virtual void playVlc(const std::string& src) override
    {
        std::cout << "Playing Video : " << src << " on VLC\n";
    }
    virtual void playMpv(const std::string& src) override
    {

    }
    virtual void playMp3(const std::string& src) override
    {

    }
};

class MpvPlayer : public AdvancedMediaPlayer
{
public :
    MpvPlayer() = default;
    virtual void playVlc(const std::string& src) override
    {

    }
    virtual void playMpv(const std::string& src) override
    {
        std::cout << "Playing Video : " << src << " on MPV\n";
    }
    virtual void playMp3(const std::string& src) override
    {
        
    }
};

class Mp3Player : public AdvancedMediaPlayer
{
public :
    Mp3Player() = default;
    virtual void playVlc(const std::string& src) override
    {

    }
    virtual void playMpv(const std::string& src) override
    {

    }
    virtual void playMp3(const std::string& src) override
    {
        std::cout << "Playing Audio : " << src << " on MP3\n";        
    }
};

class ImageViewer : public AdvancedImagePlayer
{
public :
    ImageViewer() = default;
    virtual void imageView(const std::string& src) override
    {
        std::cout << "Showing Image : " << src << " on Image Viewer.\n";
    }
    virtual void snapView(const std::string& src) override
    {

    }
};

class SnapViewer : public AdvancedImagePlayer
{
public :
    SnapViewer() = default;
    virtual void imageView(const std::string& src) override
    {

    }
    virtual void snapView(const std::string& src) override
    {
        std::cout << "Showing Image : " << src << " on Snap.\n";
    }
};

class AVAdapter : public MediaPlayer
{
public :
    AVAdapter() = default;
    virtual void play(MediaType type, MediaQuality quality, const std::string& src)
    {
        if(type == MediaType::AUDIO)
        {
            mediaPlayer = new Mp3Player();
            mediaPlayer->playMp3(src);
        }
        else if (type == MediaType::VIDEO)
        {
            if(quality >= MediaQuality::LOW && quality<= MediaQuality::MEDIUM)
            {
                mediaPlayer = new VlcPlayer();
                mediaPlayer->playVlc(src);
            }
            else if(quality == MediaQuality::HIGH)
            {
                mediaPlayer = new MpvPlayer();
                mediaPlayer->playMpv(src);
            }
        }
    }
private :
    AdvancedMediaPlayer* mediaPlayer;
};

class ImageAdapter : public MediaPlayer
{
public :
    ImageAdapter() = default;
    virtual void play(MediaType type, MediaQuality quality, const std::string& src)
    {
        if(quality == MediaQuality::LOW)
        {
            imagePlayer = new ImageViewer();
            imagePlayer->imageView(src);
        }
        else 
        {
            imagePlayer = new SnapViewer();
            imagePlayer->snapView(src);
        }
    }
private :
    AdvancedImagePlayer* imagePlayer;
};

class AllPlayer : public MediaPlayer
{
public :
    AllPlayer() = default;
    virtual void play(MediaType type, MediaQuality quality, const std::string& src)
    {
        if(type == MediaType::IMAGE)
        {
            imageAdapter = new ImageAdapter();
            imageAdapter->play(type,quality,src);
        }
        else if(type == MediaType::AUDIO || type == MediaType::VIDEO) 
        {
            audioVideoAdapter = new AVAdapter();
            audioVideoAdapter->play(type,quality,src);
        }
    }
private :
    AVAdapter* audioVideoAdapter;
    ImageAdapter* imageAdapter;
};

int main()
{
    AllPlayer myPlayer;
    myPlayer.play(MediaType::VIDEO, MediaQuality::HIGH, "Manike mange hithe");
    myPlayer.play(MediaType::IMAGE, MediaQuality::MEDIUM, "WallPaper");
    myPlayer.play(MediaType::AUDIO, MediaQuality::HIGH, "Bhoot FM");
}