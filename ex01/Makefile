NAME = program

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR	= src
SRCS	= $(wildcard $(SRCDIR)/*.cpp)
OBJDIR	= obj
OBJS	= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

run: $(NAME)
	./$(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $^ $(CXXFLAGS) -c -o $@

clean:
	$(RM) *.o
	$(RM) $(NAME)
