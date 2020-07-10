#ifndef SKIA_BUFFER_H
#define SKIA_BUFFER_H

class GraphicViewPortClass;

class GraphicViewPortClass;

/*=========================================================================*/
/* BufferClass - A base class which holds buffer information including a	*/
/*		pointer and the size of the buffer.												*/
/*=========================================================================*/
class BufferClass {
	public:
		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		BufferClass(void *ptr, long size);
		BufferClass(long size);
		BufferClass();
		~BufferClass();
		/*===================================================================*/
		/* Define functions which work with the buffer class.						*/
		/*===================================================================*/
		long To_Page(GraphicViewPortClass &view);
		long To_Page(int w, int h, GraphicViewPortClass &view);
		long To_Page(int x, int y, int w, int h, GraphicViewPortClass &view);

		/*===================================================================*/
		/* define functions to get at the protected data members					*/
		/*===================================================================*/
		void	*Get_Buffer(void);
		long	Get_Size(void);

	private:
		/*===================================================================*/
		/* Define the operators we do not want to happen which are the copy	*/
		/* and equal constructors.  These are bad because the Allocated flag	*/
		/*	could be copied and the associated buffer freed.  If this were to	*/
		/*	gappen it could cause weird general protection fault.					*/
		/*===================================================================*/
		BufferClass(BufferClass const &);
		BufferClass &operator=(BufferClass const &);

	protected:
		void	*Buffer;
		long	Size;
		bool	Allocated;
};

#endif //SKIA_BUFFER_H
