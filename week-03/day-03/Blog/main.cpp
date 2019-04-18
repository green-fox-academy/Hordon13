#include <iostream>
#include "BlogPost.h"
#include "Blog.h"

int main()
{
    BlogPost post1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost post2("Tim Urban", "Wait but why",
                   "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost post3("William Turton ", "One Engineer Is Trying to Get IBM to Reckon With Trump",
                   "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. \n"
                   "When I asked to take his picture outside one of IBM’s New York City offices, \n"
                   "he told me that he wasn’t really into the whole organizer profile thing.",
                   "2017.03.28");

    std::vector<BlogPost> currentPosts = {post1, post2, post3};

    Blog myBlog(currentPosts);

    BlogPost postAdd("Donat", "Test", "Szét adom a classokat yo!", "2019.04.18.");

    BlogPost postMod("Class Boss", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");


    for (int i = 0; i < myBlog.getAllPost().size(); ++i) {
        std::cout << myBlog.getAllPost().at(i).getAuthorName() << std::endl;
    }

    std::cout << std::endl;
    myBlog.add(postAdd);
    for (int i = 0; i < myBlog.getAllPost().size(); ++i) {
        std::cout << myBlog.getAllPost().at(i).getAuthorName() << std::endl;
    }

    std::cout << std::endl;
    myBlog.deletePost(1);
    for (int i = 0; i < myBlog.getAllPost().size(); ++i) {
        std::cout << myBlog.getAllPost().at(i).getAuthorName() << std::endl;
    }

    std::cout << std::endl;
    myBlog.update(0, postMod);
    for (int i = 0; i < myBlog.getAllPost().size(); ++i) {
        std::cout << myBlog.getAllPost().at(i).getAuthorName() << std::endl;
    }

    std::cout << std::endl;
    myBlog.update(0, postMod);
    for (int i = 0; i < currentPosts.size(); ++i) {
        std::cout << currentPosts.at(i).getAuthorName() << std::endl;
    }

    return 0;
}