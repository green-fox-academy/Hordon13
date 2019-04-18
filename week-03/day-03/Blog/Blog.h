#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H

#include <vector>
#include "BlogPost.h"


class Blog {
public:
    Blog(std::vector<BlogPost>);

    void add(BlogPost);

    void deletePost(int);

    void update(int, BlogPost);

    const std::vector<BlogPost> &getAllPost() const;

private:
    std::vector<BlogPost> _allPost;
};


#endif