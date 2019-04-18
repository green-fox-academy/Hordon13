#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H

#include <string>

class BlogPost {
public:
    BlogPost(const std::string &authorName, const std::string &title, const std::string &text,
             const std::string &publicationDate);

    const std::string &getAuthorName() const;

    void setAuthorName(const std::string &authorName);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getPublicationDate() const;

    void setPublicationDate(const std::string &publicationDate);

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
};


#endif