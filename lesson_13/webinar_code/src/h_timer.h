#ifndef H_TIMER_H__
#define H_TIMER_H__

typedef void (*H_TIMER_CB)(void);
  
void H_TimInit(H_TIMER_CB callback);


#endif /* H_TIMER_H__ */
